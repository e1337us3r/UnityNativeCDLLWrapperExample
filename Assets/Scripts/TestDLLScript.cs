using UnityEngine;
using UnityEngine.UI;

public class TestDLLScript : MonoBehaviour
{

    public Text fibonacciResultText;
    public Text censorResultText;

    public void ArrangeCubes()
    {
        // Get all childeren of the object that this script is attached to
        Transform[] ts = GetComponentsInChildren<Transform>();

        Cube[] cubes = new Cube[ts.Length - 1];

        //first element is the cubeHolder, which we ignore
        for (int i = 1; i <= cubes.Length; i++)
        {
            // record the y coord and the current index of each cube to the cubes array
            cubes[i - 1] = new Cube
            {
                y = (int)ts[i].position.y,
                index = i - 1
            };

        }

        NativeDllWrapper.SortTheCubes(cubes);

        for (int i = 0; i < cubes.Length; i++)
        {
            // assign the correct location to each cube
            // +1 is there to avoid touching cubeHolder object which is ts[0]
            Vector3 newPosition = ts[cubes[i].index + 1].position;

            newPosition.z = i;

            ts[cubes[i].index + 1].position = newPosition;

        }

    }
    public void DemoOthers()
    {
        fibonacciResultText.text = NativeDllWrapper.NthFibonacciNumber(23).ToString();

        string pattern = "damn";
        char sensorChar = '*';

        censorResultText.text = NativeDllWrapper.FindAndCensor(censorResultText.text, pattern, sensorChar);




    }
    /*private void Start()
    {
        string target = "This is a damn sentence.";
        string pattern = "damn";

        Debug.Log("Target sentence: \"" + target + "\"");

        Debug.Log("Censored sentence: \"" + NativeDllWrapper.FindAndCensor(target,pattern,'*') + "\"");

        Debug.Log("23rd term of Fibonacci is: " + NativeDllWrapper.NthFibonacciNumber(23));
    }*/



}
