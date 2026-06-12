public class Solution {
    public bool AsteroidsDestroyed(int mass, int[] asteroids) {
        Array.Sort(asteroids);

        long currentMass = mass;

        foreach(int asteroid in asteroids){
            if(currentMass >= asteroid){
                currentMass += asteroid;
            }
            else{
                return false;
            }
        }
        return true;
    }
}