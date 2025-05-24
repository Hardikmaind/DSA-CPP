#include <coroutine>
#include <iostream>
#include <thread>
#include <chrono>

// ========== Delay Awaitable ===========
struct Delay {
    int ms;

    bool await_ready() const noexcept { return false; }

    void await_suspend(std::coroutine_handle<>) const {
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
    }

    void await_resume() const noexcept {}
};

// ========== Downloader Generator ===========
struct Downloader {
    struct promise_type;
    using handle_type = std::coroutine_handle<promise_type>;

    struct promise_type {
        int progress;

        Downloader get_return_object() {
            return Downloader{handle_type::from_promise(*this)};
        }

        std::suspend_always initial_suspend() { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }

        std::suspend_always yield_value(int p) {
            progress = p;
            return {};
        }

        void return_void() {}
        void unhandled_exception() { std::exit(1); }
    };

    handle_type coro;

    Downloader(handle_type h) : coro(h) {}
    ~Downloader() { coro.destroy(); }

    bool next() {
        coro.resume();
        return !coro.done();
    }

    int getProgress() const {
        return coro.promise().progress;
    }
};

// ========== Coroutine Function ==============
Downloader downloadFile(int fileSize, int chunkSize) {
    int downloaded = 0;
    while (downloaded < fileSize) {
        co_await Delay{500};  // Simulate 500ms download per chunk
        downloaded += chunkSize;
        if (downloaded > fileSize) downloaded = fileSize;
        co_yield (downloaded * 100) / fileSize;  // Yield percentage progress
    }
    co_return;
}

// ========== Main ====================
int main() {
    Downloader d = downloadFile(1000, 250); // Total 1000 units, download 250 at a time

    while (d.next()) {
        std::cout << "Downloaded: " << d.getProgress() << "%\n";
    }

    std::cout << "Download complete!\n";
    return 0;
}
