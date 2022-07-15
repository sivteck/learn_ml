Prereqs
-------

```
$ which python3
/opt/homebrew/bin/python3
```

```
$ python3
Python 3.9.13 (main, May 24 2022, 21:13:51)
```

1. Create a directory eg. `ml_prj`, inside that create another directory `env` to install all the packages

```
python3 -m venv env
pip install tensorflow-macos
pip install tensorflow-metal
pip install tensorflow-datasets #optional
pip install jupyter pandas numpy matplotlib scikit-learn #additonal packages
```

2. Verify Setup,
```
# start juypter notebook
jupyter notebook
```
Run the following snippet, credits: https://github.com/mrdbourke/m1-machine-learning-test

```
import numpy as np
import pandas as pd
import sklearn
import tensorflow as tf
import matplotlib.pyplot as plt

# Check for TensorFlow GPU access
print(f"TensorFlow has access to the following devices:\n{tf.config.list_physical_devices()}")

# See TensorFlow version
print(f"TensorFlow version: {tf.__version__}")
```

should output if GPU is supported,
```
TensorFlow has access to the following devices:
[PhysicalDevice(name='/physical_device:CPU:0', device_type='CPU'), 
PhysicalDevice(name='/physical_device:GPU:0', device_type='GPU')]
TensorFlow version: 2.9.2
```

Note: TF might throw kernel doesn't support NUMA, M1 Mac uses UMA, so it should be fine

Setting Up PyTorch
------------------
```
pip install torch torchvision torchaudio
```

Running the following on a Jupyter Notebook
```
import torch
import numpy as np
import pandas as pd
import sklearn
import matplotlib.pyplot as plt

# Checks if Metal Performance Shader is available
torch.backends.mps.is_available()
```
should output
```
True
```