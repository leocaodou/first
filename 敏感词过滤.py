import re
def check_filter(keywords, text):
     return re.sub("|".join(keywords), "*", text)
keywords = ("垃圾","陷阱","不要脸","内幕","辣鸡")
text = input() 
print(check_filter(keywords, text))