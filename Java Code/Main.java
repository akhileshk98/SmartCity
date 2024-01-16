import java.util.Random;

class Route {
    public String name;
    public int congestionLevel;
    public boolean congestionDetected;

    public Route(String name) {
        this.name = name;
        this.congestionLevel = 0;
        this.congestionDetected = false;
    }

    public String getName() {
        return name;
    }

    public int getCongestionLevel() {
        return congestionLevel;
    }

    public boolean isCongestionDetected() {
        return congestionDetected;
    }

    public void updateCongestionLevel() {
        // Simulate congestion by generating a random number between 20 and 70
        this.congestionLevel = new Random().nextInt(101) + 0;

        // Check if congestion is detected (congestion level more than 70%)
        this.congestionDetected = this.congestionLevel > 70;
    }
}

public class Main {
    public static void main(String[] args) {
        Route routeA = new Route("Junction A");
        Route routeB = new Route("Junction B");
        Route routeC = new Route("Junction C");
        Route routeD = new Route("Junction D");

        runRouteTask(routeA, routeB, routeC, routeD);
    }

    static void runRouteTask(Route route, Route routeB, Route routeC, Route routeD) {
        while (true) {
            // Update congestion level for the route
            route.updateCongestionLevel();

            // Display congestion information for the route
            System.out.println("Changing Junction A's Signal to RED and checking for congestion in Junction A");
            System.out.print("Junction: ");
            System.out.print(route.getName());
            System.out.print(", Congestion Level: ");
            System.out.print(route.getCongestionLevel());
            System.out.println("%");

            // Check if congestion is detected
            if (route.isCongestionDetected()) {
                System.out.println("Congestion detected in Junction " + route.getName() + "!");

                // Check for congestion in other routes (B, C, D)
                int i=checkAndHandleCongestion(routeB);
                int j=checkAndHandleCongestion(routeC);
                int k=checkAndHandleCongestion(routeD);
            } else {
                System.out.println("No congestion detected. Normal flow continues");
                // Code to change the signal to green goes here
            }

            try {
                Thread.sleep(1000); // Adjust the sleep time based on your requirements
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    static int checkAndHandleCongestion(Route route) {
        // Check for congestion in the given route
        route.updateCongestionLevel();
        System.out.print("Checking congestion in " + route.getName() + "... ");

        if (route.isCongestionDetected()) {
            System.out.println("Congestion detected! Changing the junction's signal to red.");
            // Code to change the signal to red goes here
        } else {
            System.out.println("No congestion detected. Changing signal to green.");
            // Code to change the signal to green goes here
        }
        return 0;
    }
}
