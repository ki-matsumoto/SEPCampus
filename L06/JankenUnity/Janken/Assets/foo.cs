using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;

public class foo : MonoBehaviour
{
    class JankenRespons
    {
        public int computer;
        public string message;
    };

public UnityEngine.UI.Text message;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void ButtonClickGuu()
    {
        StartCoroutine(ExecuteJanken(0));
    }
    public void ButtonClickCyoki()
    {
        ExecuteJanken(1);
    }
    public void ButtonClickPaa()
    {
        ExecuteJanken(2);
    }
    IEnumerator ExecuteJanken(int you)
    {
        var url = string.Format("http://ec2-18-176-58-134.ap-northeast-1.compute.amazonaws.com/janken.php?you={0}", you);
        using (var www = UnityWebRequest.Get(url))
        {
            yield return www.SendWebRequest();

            if (www.isNetworkError || www.isHttpError)
            {
                Debug.Log(www.error);
            }
            else
            {
                // Show results as text
                var data = JsonUtility.FromJson<JankenRespons>(www.downloadHandler.text);

                message.text = data.message;
            }
        }
    }

}
