import re

text = "++1--1"
pattern = r"[0-9]([-]|[+]){2,}|^([-]|[+]){2,}"
print(re.findall(pattern, text))
print(re.findall(pattern, text,re.MULTILINE))