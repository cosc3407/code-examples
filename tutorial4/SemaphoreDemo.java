import java.util.concurrent.Semaphore;

public class SemaphoreDemo {
	
	static class Report { 
		
		int n = 0;
		
		int next() {
			
			n++;
			try {
				Thread.sleep(10);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			n++;
			
			return n;
			
		}
		
	}

	public static void main(String[] args) throws InterruptedException {
	
		Report report = new Report();
		Semaphore mutex = new Semaphore(1);
		
		Runnable job = () -> {
			
			for (int i = 1; i <= 10; i++) {
				
				try {
					mutex.acquire();
				} catch (InterruptedException e1) {
					
				}
				
   			    // critical section
				System.out.println(report.next());
				
				mutex.release();
			}
			
		};
		
		new Thread(job).start();
		new Thread(job).start();
		
	}

}
