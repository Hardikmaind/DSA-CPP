public class SynchronizedMethodExample {
    private int count = 0;

    // Synchronized method to increment count
    public synchronized void increment() {
        count++;
    }

    // Synchronized method to get the current count
    public synchronized int getCount() {
        return count;
    }

    public static void main(String[] args) {
        SynchronizedMethodExample example = new SynchronizedMethodExample();

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
