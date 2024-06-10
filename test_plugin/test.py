# test.py
import json
from py_ds_trampoline import Trampoline

def load_config(config_file):
    with open(config_file, 'r') as f:
        config = json.load(f)
    return config

class AsyncIOBuilder:
    def __init__(self, config):
        self.config = config

    def load(self):
        plugin_name = self.config.get("plugin", "plugin1")  # Default to "plugin1" if not specified
        return Trampoline(plugin_name)

# Load configuration
config = load_config("config.json")

# Create AsyncIOBuilder with the loaded configuration
aio_builder = AsyncIOBuilder(config)

# Load the plugin
aio = aio_builder.load()

# Use the plugin
aio.do_something("guna")
aio.get_handle().do_something_inner()