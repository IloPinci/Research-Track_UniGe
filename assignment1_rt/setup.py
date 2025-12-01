from setuptools import setup, find_packages

package_name = 'assignment1_rt'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', ['launch/run.py']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='snape',
    maintainer_email='snape@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    extras_require={
        'test': ['pytest'],
    },
    entry_points={
        'console_scripts': [
            'ui_node = assignment1_rt.ui_node:main',
            'distance_node = assignment1_rt.distance_node:main',
            'turtle_spawn = assignment1_rt.turtle_spawn:main',
        ],
    },
)
