from setuptools import find_packages
from setuptools import setup

setup(
    name='osm_nav_interface',
    version='0.0.0',
    packages=find_packages(
        include=('osm_nav_interface', 'osm_nav_interface.*')),
)
