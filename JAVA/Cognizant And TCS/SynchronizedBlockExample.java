public class SynchronizedBlockExample {
    private int count = 0;
    private final Object lock = new Object();

    // Method with synchronized block to increment count
    public void increment() {
        synchronized (lock) {
            count++;
        }
    }

    // Method with synchronized block to get the current count
    public int getCount() {
        synchronized (lock) {
            return count;
        }
    }

    public static void main(String[] args) {
        SynchronizedBlockExample example = new SynchronizedBlockExample();

        // Create multiple threads that increment the count
        Thread t1 = new Thread(() -> {
            for (int i = 0; i < 1000; i++) {
                example.increment();
            }
        });

        Thread t2 = new Thread(() -> {
            for (int i = 0; i < 1000; i++) {
                example.increment();
            }
        });

        t1.start();
        t2.start();

        // Wait for both threads to finish
        try {
            t1.join();
            t2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        // Print the final count
        System.out.println("Final count: " + example.getCount());
    }
}
