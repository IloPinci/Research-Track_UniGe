from setuptools import setup
import os
from glob import glob 

package_name = 'a2_python'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        
        (os.path.join('share', package_name, 'launch'), glob('launch/*.launch.py')),
        
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='snape',
    maintainer_email='snape@hogwarts.edu',
    description='Python controller for assignment 2',
    license='TODO',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'control_node = a2_python.control_node:main',
            'stat_node = a2_python.stat_node:main',
        ],
    },
)