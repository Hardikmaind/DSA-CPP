In the provided code, a **max-heap** is used to prioritize and process the class where adding an extra student will maximize the **increase in the average ratio** (i.e., the ratio of `pass` to `stren`). This approach is correct because we want to distribute the extra students to maximize the overall average ratio across all classes.

### Why Max-Heap Instead of Min-Heap?

The goal is to maximize the **overall average ratio** after distributing the extra students. To achieve this, we must add students to the class where the **incremental gain** in the pass ratio (the improvement in `pass / stren`) is the largest. The **max-heap** helps in always picking the class with the highest gain efficiently.

#### Key points

1. **Gain Calculation**:
   - For a class with `pass` students and `stren` strength, adding one student increases the ratio by:
     \[
     \text{gain} = \frac{\text{pass} + 1}{\text{stren} + 1} - \frac{\text{pass}}{\text{stren}}
     \]
   - This measures how much improvement we can achieve in the average if we add an extra student to this class.

2. **Greedy Strategy**:
   - Since we aim to maximize the overall average ratio, we must allocate each extra student to the class with the **highest possible gain** at that moment.
   - A **max-heap** ensures that at every step, we process the class with the highest gain. This keeps the approach optimal.

#### Why Not Use a Min-Heap?

A **min-heap** would prioritize the class with the **lowest gain**. This would be suboptimal because:

- Allocating extra students to classes with lower gains reduces the potential for maximizing the overall average.
- For example, if one class has a potential gain of `0.1` and another class has a gain of `0.5`, allocating the extra student to the class with a gain of `0.1` would leave a better opportunity wasted.

### Example

Suppose there are two classes:

- Class A: \( \text{pass} = 1, \text{stren} = 2 \)
- Class B: \( \text{pass} = 3, \text{stren} = 5 \)

If we add an extra student:

- Gain for Class A:
  \[
  \text{gain} = \frac{1+1}{2+1} - \frac{1}{2} = \frac{2}{3} - 0.5 = 0.1667
  \]
- Gain for Class B:
  \[
  \text{gain} = \frac{3+1}{5+1} - \frac{3}{5} = \frac{4}{6} - 0.6 = 0.0667
  \]

Using a max-heap, we prioritize Class A because it has the higher gain.

### Why This Works

The greedy approach ensures that at every step, the decision taken yields the **maximum immediate benefit** to the overall average. This is why the **max-heap** is essential to efficiently implement this strategy.
