import jieba
txt = open("hlm_utf_8.txt", "r", encoding='utf-8').read()
words = jieba.lcut(txt)
counts = {}
biaodian =" …《》，、。？！；：“”‘’'\n\r-=—()（）.【】『』"
for word in words:
	if word in biaodian:
		word = '#'
	if "第" in word:
		if '回' in word:
			continue
	counts[word] = counts.get(word, 0) + 1

items = list(counts.items())
items.sort(key=lambda x: x[1], reverse=True)
i = 0
while(True):
    word, count = items[i]
    if(count < 100):
    	break
    print("{0:<5}{1:>5}".format(word, count))
    i = i + 1