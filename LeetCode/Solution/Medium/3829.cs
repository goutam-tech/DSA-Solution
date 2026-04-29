public class RideSharingSystem
{
    private readonly Queue<int> riders;
    private readonly Queue<int> drivers;
    private readonly HashSet<int> cancelledRiders;
    private readonly HashSet<int> activeRiders;

    public RideSharingSystem()
    {
        riders = new Queue<int>();
        drivers = new Queue<int>();
        cancelledRiders = new HashSet<int>();
        activeRiders = new HashSet<int>();
    }

    public void AddRider(int riderId)
    {
        // Only add if not already cancelled before arriving
        if (!cancelledRiders.Contains(riderId))
        {
            riders.Enqueue(riderId);
            activeRiders.Add(riderId);
        }
        else
        {
            // Discard the pre-cancellation — it was for a non-existent rider
            cancelledRiders.Remove(riderId);
        }
    }

    public void AddDriver(int driverId)
    {
        drivers.Enqueue(driverId);
    }

    public int[] MatchDriverWithRider()
    {
        // Skip cancelled riders
        while (riders.Count > 0 && cancelledRiders.Contains(riders.Peek()))
        {
            cancelledRiders.Remove(riders.Peek());
            activeRiders.Remove(riders.Dequeue());
        }

        if (drivers.Count == 0 || riders.Count == 0) return [-1, -1];

        int rider = riders.Dequeue();
        activeRiders.Remove(rider);
        return [drivers.Dequeue(), rider];
    }

    public void CancelRider(int riderId)
    {
        // Only cancel if rider is currently active in the queue
        if (activeRiders.Contains(riderId))
        {
            cancelledRiders.Add(riderId);
            activeRiders.Remove(riderId);
        }
    }
}