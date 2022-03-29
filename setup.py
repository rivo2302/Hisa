import setuptools

with open("README.md", "r") as fh:
    long_description = fh.read()

setuptools.setup(
    name="hisa",  
    packages = ["hisa"],              # This is the name of the package
    version="0.0.2",                      # The initial release version
    author="rivo2302",    
    author_email = 'rivo.rajaonarivony@esti.mg',      # Type in your E-Mail
    url = 'https://github.com/rivo2302/Hisa',   # Provide either the link to your github or to your website
    keywords = ['MALAGASY', 'TRANSALATE', 'INTEGER'],                       # Full name of the author
    description="module that translates a number into Malagasy letters",
    long_description=long_description,  # Long description read from the readme
    long_description_content_type="text/markdown",
    classifiers=[
        "Programming Language :: Python :: 3",
        "License :: OSI Approved :: MIT License",
        "Operating System :: OS Independent",
    ],                      # Information to filter the project on PyPi website
    python_requires='>=3.6',
    install_requires=[ ],  # depandance
    include_package_data=True,         # Include all data file with the package
    package_data={'': ['*.json']},
)