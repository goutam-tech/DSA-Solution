using System.Numerics;
public class Solution {
    public IList<string> ReadBinaryWatch(int turnedOn) {
        List<string> result = new List<string>();

        for(int hour = 0; hour < 12; hour++){
            for(int minute = 0; minute < 60; minute++){
                if(BitOperations.PopCount((uint)hour) + BitOperations.PopCount((uint)minute) == turnedOn){
                    result.Add($"{hour}:{minute:D2}"); 
                }
            }
        }
        return result;
    }
}