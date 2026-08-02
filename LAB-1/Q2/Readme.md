# 🪙 DAA Lab 01 – Question 2: Fair vs. Biased Coin Toss Simulation

---

# 📚 Introduction

This repository contains the implementation for **Question 2** of the **Design and Analysis of Algorithms (DAA) Laboratory – Assignment 01**.

The objective of this experiment is to simulate the behavior of both a **fair coin** and a **biased coin** using the C programming language. Rather than performing a few manual coin tosses, the program conducts **10,000 independent tosses** for each type of coin to observe how experimental probability approaches the theoretical probability as the number of trials increases.

This experiment demonstrates one of the most important concepts in probability and algorithm analysis: **the Law of Large Numbers**. As the number of trials increases, the observed (experimental) probability becomes increasingly close to the expected (theoretical) probability.

An accompanying **SVG visualization** is included in this repository to provide a graphical comparison between the theoretical expectations and the experimental outcomes obtained from the simulation.

---

# 🎯 Objective

The primary objectives of this experiment are:

- To simulate the tossing of a fair coin using random number generation.
- To simulate a mathematically biased coin with a predefined probability.
- To compare theoretical probabilities with experimentally observed probabilities.
- To understand how randomness behaves over a large number of trials.
- To analyze the effect of probability bias in repeated experiments.
- To visualize the results using the provided SVG graph.

---

# 📝 Problem Statement

Develop a C program that simulates two different types of coins:

1. A **Fair Coin**, where the probability of obtaining Heads and Tails is equal.
2. A **Biased Coin**, where the probability of obtaining Heads is intentionally increased to **75%**, leaving a **25%** probability for Tails.

The program performs **10,000 independent coin tosses** for each coin, records the number of Heads and Tails obtained, calculates the experimental probability of Heads, and compares the results with the expected theoretical probabilities.

---

# 💡 Methodology

The simulation is implemented using the **C programming language**.

Random outcomes are generated using the built-in `rand()` function. To ensure different random sequences every time the program executes, the random number generator is initialized using the current system time through `srand(time(NULL))`.

The program separately simulates a fair coin and a biased coin, counts the number of Heads and Tails obtained during 10,000 tosses, and finally computes the experimental probability using the formula:

```
Experimental Probability = (Number of Heads / Total Tosses) × 100
```

The results are then displayed in a well-formatted table.

---

# ⚙️ Simulation Logic

## 1. Fair Coin Simulation

A fair coin gives equal probability to both possible outcomes.

The program generates a random number using:

```c
rand() % 2
```

Possible outcomes are:

- `0` → Heads
- `1` → Tails

Since only two equally likely outcomes exist, each toss has a theoretical probability of:

- Heads = **50%**
- Tails = **50%**

This accurately models the behavior of an unbiased coin.

---

## 2. Biased Coin Simulation

The biased coin is designed to favor Heads.

The program generates a random number using:

```c
rand() % 100
```

The generated value lies between **0 and 99**.

The decision rule is:

- Values **0–74** → Heads
- Values **75–99** → Tails

Therefore,

- Heads occurs for **75** possible values.
- Tails occurs for **25** possible values.

This creates the following probability distribution:

- Heads = **75%**
- Tails = **25%**

The algorithm provides a simple and effective way to simulate a weighted coin using uniformly distributed random numbers.

---

# 📖 Observations

### 1. Fair Coin

The fair coin simulation produced nearly equal numbers of Heads and Tails.

Although the results are not perfectly 50–50, they remain extremely close to the theoretical probability. Such minor variations are expected because random events naturally fluctuate.

As the number of tosses increases even further, the experimental probability would continue moving closer to the expected value of **50%**.

---

### 2. Biased Coin

The biased coin consistently produced significantly more Heads than Tails.

The experimental probability closely matched the intended probability of **75%**, demonstrating that the implemented algorithm successfully introduces the desired bias into the simulation.

---

### 3. Effect of Large Sample Size

Conducting **10,000 trials** greatly reduces random fluctuations compared to performing only a small number of tosses.

This experiment illustrates the **Law of Large Numbers**, which states that experimental results converge toward theoretical probabilities as the number of observations increases.

---

# 📊 Experimental Results

The following table summarizes the outcomes obtained from the simulation.

| Coin Type | Theoretical Probability (Heads) | Total Heads | Total Tails | Experimental Probability |
| :--- | :--- | :--- | :--- | :--- |
| **Fair Coin** | 50.00% | 5,042 | 4,958 | **50.42%** |
| **Biased Coin** | 75.00% | 7,481 | 2,519 | **74.81%** |

---

# 📈 Result Analysis

## Fair Coin

- Expected Probability of Heads = **50%**
- Experimental Probability = **50.42%**

The difference between the theoretical and experimental values is only **0.42%**, indicating that the simulation accurately represents a fair coin.

---

## Biased Coin

- Expected Probability of Heads = **75%**
- Experimental Probability = **74.81%**

The difference is only **0.19%**, confirming that the algorithm successfully models a coin with a 75% chance of producing Heads.

---

# 📊 Graphical Representation

An **SVG graph** has been included in this repository to visually compare the outcomes of the two simulations.

The graph clearly highlights the difference between the fair and biased coins by showing:

- Theoretical probability versus experimental probability.
- Distribution of Heads and Tails for both coin types.
- The close agreement between expected values and observed results after 10,000 trials.

The visualization makes it easy to understand how increasing the probability of Heads changes the distribution of outcomes while still preserving the random nature of individual tosses.

---

# 🔍 Key Findings

- Random number generation can effectively simulate probabilistic events.
- A fair coin produces approximately equal numbers of Heads and Tails.
- A biased coin consistently favors one outcome according to the specified probability.
- Increasing the number of trials improves the accuracy of experimental probability.
- Small deviations from theoretical values are expected because of random variation.
- The experimental results closely validate the theoretical expectations for both simulations.

---

# ✅ Conclusion

This experiment successfully demonstrates how probability can be simulated using random number generation in C.

The fair coin simulation produced an experimental probability of **50.42%**, while the biased coin produced **74.81%**, both of which are remarkably close to their theoretical probabilities of **50%** and **75%**, respectively.

The numerical results, together with the accompanying SVG visualization, confirm that increasing the number of trials leads to experimental outcomes that closely approximate theoretical predictions. This experiment provides a practical understanding of probability, randomness, simulation techniques, and the importance of large sample sizes in statistical analysis.
