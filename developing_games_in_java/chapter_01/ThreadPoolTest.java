public class ThreadPoolTest {
  public static void main(String[] args) {
    if (args.length != 2) {
      System.out.println("Tests the ThreadPool task");
      System.out.println("Usage: java ThreadPoolTest numTasks numThreads");
      System.out.println("  numTasks - integer: number of tasks to run");
      System.out.println("  numThreads - integer: number of threads in the thread pool");
      return;
    }
    int numTasks = Integer.parseInt(args[0]);
    int numThreads = Integer.parseInt(args[1]);

    // Create the thread pool
    ThreadPool threadPool = new ThreadPool(numThreads);

    // Run example tasks
    for (int i = 0; i < numTasks; i++) {
      threadPool.runTask(createTask(i));
    }

    // Close the pool and wait for all the tasks to finish
    threadPool.join();
  }

  private static Runnable createTask(final int taskID) {
    return new Runnable() {
    
      @Override
      public void run() {
        System.out.println("Task:" + taskID + ": start");

        // Simulate a long running task
        try {
          Thread.sleep(500);
        }
        catch (InterruptedException e) {
          // do nothing
        }

        System.out.println("Task:" + taskID + ": end");
      }
    };
  }
}
