#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Oct  1 13:58:28 2017

@author: yoovrajshinde
"""

from flask import Flask, request
from flask_restful import Resource, Api
from json import dumps
from flask_jsonpify import jsonify
import serial

app = Flask(__name__)
api = Api(app)
ser = serial.Serial('/dev/tty.usbmodem1421')


class Motor(Resource):
    def get(self, motor_id=0, angle=0, operation_id=0):
        print("get")
        if operation_id == 'close':
            print("closing port")
            ser.close()
            return jsonify({'result':'success_close'})
        elif operation_id == 'open':
            print("opening port")
            ser.open()
            return jsonify({'result':'success_open'})
        
        print("writing value motor={} angle={}".format(motor_id, angle))
        command = "{}_{}".format(motor_id, angle)
        print("command = {}".format(command))
        if not ser.isOpen():
            ser.open()
        ser.write(command.encode());
        
        return jsonify({'result':'success_write'})


api.add_resource(Motor, '/motor/<motor_id>/<angle>', endpoint="motor")
api.add_resource(Motor, '/motor/<operation_id>', endpoint="motors")



if __name__ == '__main__':
     app.run(host='0.0.0.0')

