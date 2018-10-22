#!/usr/bin/env python
import os
import rospy
from std_msgs.msg import String
from std_srvs.srv._SetBool import *
from move_task_msgs.msg import *
from move_task_msgs.srv import *
from visual_servo_msgs.msg._IbvsConstrainedAction import *
from visual_servo_msgs.srv._VisualServoTeaching import *
from move_task_msgs.msg._MoveTaskAction import *

class TestNode(object):
    'test node class'
    def __init__(self):
        self.move_pub = rospy.Publisher('')
        self.follow_line_pub = rospy.Publisher('')
        self.teaching_srv = rospy.ServiceProxy('')
        self.follow_result_sub = rospy.Subscriber('')
        self.f = open(os.getenv('HOME'), 'w')


    def follow_line_result_callback(self, msg):
        query = VisualServoTeachingRequest()
        query.camera_type = query.DOWN_CAMERA
        query.tag_type = query.SHELF_TAG
        response = self.teaching_srv.call(query)

        x = response.x
        y = response.y
        theta = response.theta
        self.f.write(x)
        self.f.write('\t')
        self.f.write(y)
        self.f.write('\t')
        self.f.write(theta)
        self.f.write(os.linesep)

def main():
    move_pub = rospy.Publisher('')
    follow_line_pub = rospy.Publisher('')
    teaching_srv = rospy.Service('')
    #

    rospy.init_node("First_Python_Test_Node")
    print("First Python Test Node Start")

    while(!rospy.is_shutdown()):
        move_pub.publish()
        follow_line_pub.publish()
        teaching_srv.


    tn = FirstPythonNode()
    rospy.spin()
    pass

if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException:
        pass