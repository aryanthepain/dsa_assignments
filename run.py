import os

try:
    os.chdir("Assignment-8")
    print("Directory changed successfully.")
except OSError:
    print("Error changing directory.")
