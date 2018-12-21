using System;
using System.Runtime.InteropServices;
using UnityEngine;

public class NativeDllWrapper : MonoBehaviour
{
    
    [DllImport("Dll1")]
    public static extern int NthFibonacciNumber(int n);

    [DllImport("Dll1", CharSet = CharSet.Ansi)]
    private static extern IntPtr DeletePattern(string target, string pattern, int targetLenght, int patternLenght, char replacementChar);

    [DllImport("Dll1")]
    private static extern void SortCubeArray(Cube[] cubes, int cubeCount);

    public static void SortTheCubes(Cube[] cubes)
    {
        // Do inplace sort for cubes array
        SortCubeArray(cubes, cubes.Length);
    }

    public static string FindAndCensor(string targetString, string pattern, char sensorChar)
    {
        
        IntPtr stringPtr = DeletePattern(targetString, pattern, targetString.Length, pattern.Length, sensorChar);

        string censoredSentence = Marshal.PtrToStringAnsi(stringPtr);

        return censoredSentence;

    }

}

public struct Cube
{
    public int y, index;
}