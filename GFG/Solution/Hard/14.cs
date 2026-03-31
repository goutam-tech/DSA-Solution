class kQueues
{
    int[] arr, front, rear, next;
    int free;

    public kQueues(int n, int k)
    {
        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        next = new int[n];

        for (int i = 0; i < k; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }

        for (int i = 0; i < n - 1; i++)
            next[i] = i + 1;

        next[n - 1] = -1;
        free = 0;
    }

    public bool enqueue(int x, int i)
    {
        if (isFull())
            return false;

        int idx = free;
        free = next[idx];

        if (front[i] == -1)
            front[i] = idx;
        else
            next[rear[i]] = idx;

        next[idx] = -1;
        rear[i] = idx;
        arr[idx] = x;

        return true;
    }

    public int dequeue(int i)
    {
        if (isEmpty(i))
            return -1;

        int idx = front[i];
        front[i] = next[idx];

        if (front[i] == -1)
            rear[i] = -1;

        next[idx] = free;
        free = idx;

        return arr[idx];
    }

    public bool isEmpty(int i)
    {
        return front[i] == -1;
    }

    public bool isFull()
    {
        return free == -1;
    }
}