from setuptools import find_packages
from setuptools import setup

setup(
    name='a2_controller',
    version='0.0.0',
    packages=find_packages(
        include=('a2_controller', 'a2_controller.*')),
)
