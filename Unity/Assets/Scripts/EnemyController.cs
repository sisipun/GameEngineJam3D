using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyController : MonoBehaviour
{
    // Start is called before the first frame update
    public GameObject player;
    public float speed;

    private Rigidbody rb;

    void Start ()
    {
        rb = GetComponent<Rigidbody>();
    }

    void LateUpdate ()
    {
        Vector3 movement = player.transform.position - transform.position;
        movement.y = 0;

        rb.AddForce(speed * movement);
    }
}
