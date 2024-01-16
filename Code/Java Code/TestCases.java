import org.junit.Test;
import static org.junit.Assert.*;

public class TestCases {

    //checks if cong level is above 70, getCongestionLevel returns true
    @Test
    public void testIsCongestionDetected() {
        Route route = new Route("Junction A");
        route.updateCongestionLevel();
        if(route.getCongestionLevel()>70)
        {
            assertTrue(route.isCongestionDetected());
        }  
    }
    
    //checks if cong level is blo 70, getCongestionLevel returns False
    @Test
    public void testIsCongestionNotDetected() {
        Route route = new Route("Junction A");
        route.updateCongestionLevel();
        if(route.getCongestionLevel()<70)
        {
            assertFalse(route.isCongestionDetected());
        }
    }

    //checks if there is congestion in route A, checkAndHandleCongestion is being called
    @Test
    public void testCheckAndHandleCongestionDetected() {
        Route route = new Route("Junction A");
        int i=route.getCongestionLevel();
        if(route.congestionDetected)
        {
            int flag=checkAndHandleCongestion(route);
            assertEquals(0,route.isCongestionDetected());
        }
    }

    //checks if there is NOOOOO congestion in route A, checkAndHandleCongestion is NOT being called
    @Test
    public void testCheckAndHandleCongestionNotDetected() {
        Route route = new Route("Junction A");
        int i=route.getCongestionLevel();
        if(route.congestionDetected != true)
        {
            int flag=checkAndHandleCongestion(route);
            assertNotEquals(0,route.isCongestionDetected());
        }
    }
    int checkAndHandleCongestion(Route route) {
        route.updateCongestionLevel();
        if (route.isCongestionDetected()) {
            System.out.println("Congestion detected! Changing signal to red.");
            System.out.println("Changing Signal in the previous signal to red.");
        } else {
            System.out.println("No congestion detected. Changing signal to green.");
        }
        return 0;
    }

    //Checking if congestion value is being updated or not when CongestionValUpdate() is called
    @Test
    public void CongestionValUpdate() {
        // Creating a route for testing
        Route route = new Route("Junction A");

        // Save the initial congestion level
        int initialCongestionLevel1 = route.getCongestionLevel();
        route.updateCongestionLevel();
        int x=route.getCongestionLevel();
        // Update the congestion level

        // Assert that the congestion level has been updated
        assertNotEquals(initialCongestionLevel1, x);
    }
}
