import numpy as np
import matplotlib.pyplot as plt

n = 10
total_trials = 1000
initial_trials = 10
epsilon = 0.1
x_1 = [i + 1 for i in range(initial_trials)]
x_2 = [i + 1 for i in range(total_trials)]
x_n = [i + 1 for i in range(n)]
mu = 2 * np.random.random_sample(size=(n)) - 1
sigma = np.random.random_sample(size=(n))
ave = np.zeros(n)
oa = [0]
trials = np.zeros(n, dtype=int)
score = []
avg_reward = [0]
for i in range(initial_trials):
    r = np.random.randint(0, n - 1, size=1)[0]
    s = np.random.normal(mu[r], sigma[r], 1)[0]
    if r == np.argmax(mu):
        oa.append(((oa[-1] * i / 100) + 1) * 100 / (i + 1))
    else:
        oa.append(((oa[-1] * i) / 100) * 100 / (i + 1))
    ave[r] = (ave[r] * trials[r] + s) / (trials[r] + 1)
    trials[r] += 1
    score.append(s)
    avg_reward.append(((avg_reward[-1] * i) + s) / (i + 1))
fig, axs = plt.subplots(2, 2)
axs[0, 0].plot(x_1, score)
axs[0, 0].set_title("Score obtained at each iteration")
axs[0, 1].bar(x_n, trials)
axs[0, 1].set_title("Number of trials for each slot")
axs[1, 0].plot(x_1, oa[1:])
axs[1, 0].set_title("Percentage of optimal action taken")
axs[1, 1].plot(x_1, avg_reward[1:])
axs[1, 1].set_title("Average reward after each iteration")
plt.show()
for i in range(initial_trials, total_trials):
    if np.random.random_sample(size=(1))[0] > epsilon:
        r = np.argmax(ave)
    else:
        r = np.random.randint(0, n - 1, size=1)[0]
    s = np.random.normal(mu[r], sigma[r], 1)[0]
    if r == np.argmax(mu):
        oa.append(((oa[-1] * i) / 100 + 1) * 100 / (i + 1))
    else:
        oa.append(((oa[-1] * i) / 100) * 100 / (i + 1))
    ave[r] = (ave[r] * trials[r] + s) / (trials[r] + 1)
    trials[r] += 1
    score.append(s)
    avg_reward.append(((avg_reward[-1] * i) + s) / (i + 1))
fig, axs = plt.subplots(2, 2)
axs[0, 0].plot(x_2, score)
axs[0, 0].set_title("Score obtained at each iteration")
axs[0, 1].bar(x_n, trials)
axs[0, 1].set_title("Number of trials for each slot")
axs[1, 0].plot(x_2, oa[1:])
axs[1, 0].set_title("Percentage of optimal action taken")
axs[1, 1].plot(x_2, avg_reward[1:])
axs[1, 1].set_title("Average reward after each iteration")
plt.show()
