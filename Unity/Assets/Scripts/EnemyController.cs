using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using static DebugUtilities;

public class EnemyController : MonoBehaviour {
    // Start is called before the first frame update
    public GameObject player;
    public float velocity;

    private Rigidbody rb;

    void Start () {
        rb = GetComponent<Rigidbody>();
    }

    void LateUpdate () {
        if (!CheckPath(transform.position, player.transform.position)) {
            Vector3 movement = player.transform.position - transform.position;
            movement.y = 0;
            
            rb.AddForce(velocity * movement);
        }
    }

    private bool CheckPath(Vector3 position, Vector3 target) {
        Vector3 halfExtents = Vector3.one / 10f;
        
        Quaternion rotation = Quaternion.LookRotation(target - position);
        Vector3 direction = target - position;
        float distance = Vector3.Distance(position, target);

        RaycastHit[] rhit = Physics.BoxCastAll(position, halfExtents, direction, rotation, distance);
        bool result = false;

        foreach(RaycastHit elem in rhit) {
            if (elem.collider.tag == "Maze") {
                result = true;
            }
        }

        // Vector3 center = Vector3.Lerp(position, target, 0.5f);
        // halfExtents = new Vector3(0.1f, 0.1f, (target - position).magnitude) / 2;
        // DebugUtilities.DrawBox(center, halfExtents, rotation, result ? Color.green : Color.red);

        return result;
    }

}
