using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class HeroController : MonoBehaviour
{
    
    public float velocity;
    public float jumpVelocity;
    public Text scoreText;
    public Text winText;
    public int winCondition;
    public AudioSource bonusSound;
    public AudioSource deathSound;

    private Rigidbody rb;
    private int score;
    private bool dead;
    private bool win;
    private bool isJumped;

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

        Vector3 movement = new Vector3(mh, 0, mv);

        if (!isJumped && Input.GetKeyDown("space")) {
            movement.y = jumpVelocity;
            isJumped = true;
        }

        rb.AddForce(velocity * movement);
    }

    void OnTriggerEnter(Collider other) {
        if (other.gameObject.CompareTag("Bonus")) {
            other.gameObject.SetActive(false);
            score += 1;
            bonusSound.Play();
            SetText();
        }
    }

    void OnCollisionEnter(Collision other) {
        if (other.gameObject.CompareTag("Enemy")) {
            dead = true;
            SetText();
            deathSound.Play();
        } else if (other.gameObject.CompareTag("Ground")) {
            isJumped = false;
        }
    }

    void SetText() {
        if (win) {
            return;
        }
        if (dead) {
            winText.text = "You lost";
            velocity = 0;
            return;
        }

        scoreText.text = "Score: " + score.ToString();
        if (score >= winCondition) {
            winText.text = "You win";
            velocity = 0;
            win = true;
        }
    }
}
