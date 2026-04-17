using System.Collections.Generic;

namespace GFG.Solution.Hard
{
    public class LRUCache {
        private readonly int capacity;
        private readonly Dictionary<int, LinkedListNode<(int key, int value)>> map;
        private readonly LinkedList<(int key, int value)> list;

        public LRUCache(int cap) {
            capacity = cap;
            map = new Dictionary<int, LinkedListNode<(int, int)>>();
            list = new LinkedList<(int, int)>();
        }

        public int get(int key) {
            if (!map.ContainsKey(key)) return -1;
            var node = map[key];
            int val = node.Value.value;
            list.Remove(node);
            var newNode = new LinkedListNode<(int, int)>((key, val));
            list.AddFirst(newNode);
            map[key] = newNode;
            return val;
        }

        public void put(int key, int value) {
            if (map.TryGetValue(key, out var oldNode)) {
                list.Remove(oldNode);
            } else if (map.Count == capacity) {
                var lru = list.Last;
                map.Remove(lru.Value.key);
                list.RemoveLast();
            }
            var newNode = new LinkedListNode<(int, int)>((key, value));
            list.AddFirst(newNode);
            map[key] = newNode;
        }
    }
}