import matplotlib.pyplot as plt

max_depth = []
avg_depth = []
max_children = []

fig, axs = plt.subplots(3)

with open("out.csv", "r") as f:
	flag = 0
	for line in f.readlines():
		if flag == 0:
			flag += 1
			continue
		line = line.split(',')
		max_depth.append(line[1])
		avg_depth.append(line[2])
		max_children.append(line[3])

axs[0].plot(max_depth)
axs[1].plot(avg_depth)
axs[2].plot(max_children)

plt.savefig('graph.png')