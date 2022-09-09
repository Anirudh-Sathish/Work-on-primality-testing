# -*- coding: utf-8 -*-
"""
Created on Thu Sep  8 15:53:38 2022

@author: aniru
"""

import boto3

from braket.aws import AwsDevice
from braket.circuits import Circuit
from braket.devices import LocalSimulator


# instantiate the local simulator
local_sim = LocalSimulator()

bell = Circuit().h(0).cnot(0, 1)
result = local_sim.run(bell, shots=1000).result()
counts = result.measurement_counts
print(counts)

print(task.result().measurement_counts)