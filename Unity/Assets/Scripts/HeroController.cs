using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class HeroController : MonoBehaviour
{
    
    public float speed;
    public Text scoreText;
    public Text winText;
    public int winCondition;

    private Rigidbody rb;
    private int score;
    private bool dead;
    private bool win;

    // Start is called before the first frame update
    void Start()
    {
        rb = GetComponent<Rigidbody>();
        score = 0;
        dead = false;
        win = false;
        winText.text = "";
        scoreText.text = "Score: " + score.ToString();
    }

    // Update is called once per frame
    void FixedUpdate()
    {
        float mh = Input.GetAxis("Horizontal");
        float mv = Input.GetAxis("Vertical");

        Vector3 movement = new Vector3(mh, 0f, mv);

        rb.AddForce(speed * movement);
    }

    void OnTriggerEnter(Collider other) {
        if (other.gameObject.CompareTag("Bonus")) {
            other.gameObject.SetActive(false);
            score += 1;
            SetText();
        }
    }

    void OnCollisionEnter(Collision other) {
        if (other.gameObject.CompareTag("Enemy")) {
            dead = true;
            SetText();
        }
    }

    void SetText() {
        if (win) {
            return;
        }
        if (dead) {
            winText.text = "You lost";
            speed = 0;
            return;
        }

        scoreText.text = "Score: " + score.ToString();
        if (score >= winCondition) {
            winText.text = "You win";
            speed = 0;
            win = true;
        }
    }
}
