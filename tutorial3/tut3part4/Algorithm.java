/**
 * Interface representing a generic scheduling algorithm.
 *
 */

public interface Algorithm
{
    /**
     * Invokes the scheduler
     */
    public abstract void schedule();

    /**
     * Selects the next task using the appropriate scheduling algorithm
     */
    public abstract Task pickNextTask();
}
