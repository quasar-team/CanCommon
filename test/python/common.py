import sys
import os

# Add the path to the directory containing the module
os.environ["LD_LIBRARY_PATH"] = (
    os.path.join(os.getcwd(), "build") + ":" + os.environ.get("LD_LIBRARY_PATH", "")
)

sys.path.append(os.path.join(os.getcwd(), "build"))

from canmodule import *
