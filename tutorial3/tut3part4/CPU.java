/**
 * "Virtual" CPU
 *
 * This virtual CPU also maintains system time.
 *
 */
 
public class CPU
{
    /**
     * Run the specified task for the specified slice of time.
     */
    public static void run(Task task, int slice) {
        System.out.println("Will run " + task);
    }
}
