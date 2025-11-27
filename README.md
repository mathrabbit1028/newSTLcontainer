# BunnySort (Research)

## Motivation

Sorting large-scale integer or floating-point datasets poses challenges for conventional counting sort or radix sort due to memory constraints. However, by leveraging intrinsic properties of integers and real numbers, it becomes possible to develop sorting methods faster than comparison-based algorithms. To achieve this, we train an MLP that learns the distribution of the input data and predicts the approximate position of each element in the sorted order, generating an almost-sorted array. Finally, we apply an adaptive sort to efficiently complete the sorting process.

정수 또는 실수를 정렬할 때, 데이터의 크기가 큰 경우에는 counting sort와 radix sort와 같은 정렬 방식은 적용하기 어렵다. 하지만 정수와 실수의 성질을 사용한다면 비교기반보다 더 빠른 정렬 방식을 충분히 사용할 수 있다. 이것을 위해 데이터의 분포를 학습한 MLP를 이용해, 주어진 수가 정렬된 배열에서 있을 위치를 추측하여 거의 정렬된 배열을 만들고, adaptive sort를 이용하여 배열을 정렬한다.

## Problem Definition

Given $n$ numbers, output their sorted order under the following conditions:

1. The $n$ numbers are integers between $1$ and $k$, sampled from a uniform distribution.  
2. The $n$ numbers are sampled from **a mixture of three Gaussian distributions**.

$n$개의 수가 주어질 때, 정렬한 결과를 출력하라. 단, 

1. $n$개의 수는 $1$ 이상 $k$ 이하의 정수로, 균일분포에서 샘플된다.
2. $n$개의 수는 **세 개의 정규분포의 합분포에서 샘플**된다.

## Algorithms

We assume that the distribution of the given dataset can be represented as a mixture of three Gaussian distributions. Under this assumption, 512 elements are randomly sampled from the array to estimate the CDF using an MLP. This estimated CDF allows us to predict the quantile-position of each element in the final sorted order. 

The entire array is divided into $B=n/8$ buckets, and each element is inserted into a bucket based on its predicted location. Because elements rarely fall into incorrect buckets, concatenating the buckets followed by adaptive sorting completes the procedure very efficiently.

주어진 데이터의 분포가 세 개의 정규분포의 합으로 표현될 수 있다고 가정한다. 이 가정 하에서 512개의 변수를 배열에서 랜덤으로 취한 뒤 CDF를 예측한다. 이 CDF를 바탕으로 주어진 수가 배열 상에서 몇 분위 위치에 존재하는지 예측할 수 있다.

전체를 $B=n/8$개의 버킷으로 나누고, 예측된 위치를 바탕으로 버킷에 넣는다. 이제 버킷을 다 합치면 다른 버킷에 들어가있는 경우가 거의 없으므로 adaptive sort를 하면 빠르게 정렬을 완료할 수 있다.

## Performance

Subproblem 1:

| $n$        | $k$        | Our Method | RandQS   | Merge sort | Introsort |
|------------|------------|------------|----------|------------|-----------|
| $10^6$     | $10^9$     | 6.44e-2    | 7.93e-2  | 3.91e-1    | 8.86e-2   |
| $10^6$.    | $10^6$     | 7.23e-2    | 8.55e-2  | 4.21e-1    | 9.53e-2   |
| $10^6$     | $10^3$     | 5.80e-2    | 5.42e-2  | 3.89e-1    | 7.34e-2   |


Subproblem 2:

| $n$        | $2^{20} \cdot 10$   | $2^{20} \cdot 50$   | $2^{20} \cdot 100$   | $2^{20} \cdot 300$.  |
|------------|---------------------|---------------------|----------------------|----------------------|
| Hybrid     | 0.6546              | 3.6405              | 8.0628               | 24.4638              |
| RandQS     | 0.7846              | 4.4308              | 9.6221               | 29.3900              |


# Binary Sort Improve

## Motivation

If an MLP can predict the approximate quantile position of a target value, we can accelerate binary search by beginning the search in its neighborhood.

MLP로 특정 수의 위치가 몇 분위에 위치하는지 예측할 수 있다면, 그 근처에서부터 탐색함으로써 이분탐색을 개선할 수 있다.

## Problem Definition

Given a sorted array of $n$ integers sampled uniformly from $[1, k]$ find the position of an input value $x$ in the array.

$1$ 이상 $k$ 이하의 정수로, 균일분포에서 샘플된 $n$개의 수가 정렬된 배열이 주어진다. 입력으로 주어진 수 $x$가 몇 번째에 위치하는지 찾아라.

## Algorithms

The position predicted by the MLP provides information about only one side of the search range. To resolve this, binary jumping is used to locate the opposite boundary, thereby identifying a plausible search interval. Binary search is then applied inside this interval. If the prediction error is smaller than $O(\sqrt{n})$, the effective complexity becomes equivalent to performing two binary searches, resulting in an improvement over the original binary search.

MLP로 찾은 위치는 한쪽 끝의 정보만을 제공할 것이다. 이것의 해결을 위해 binary jump로 반대쪽 끝을 찾는다. 즉, 답이 될 수 있는 구간을 미리 확정하는 것이다. 이 이후에는 일반적인 이분탐색을 진행한다. 오차가 $O(\sqrt n)$보다 작다면, 사실상 이분 탐색을 두 번 하는 것이기 때문에, 원래의 이분탐색보다 더 빠르게 된다.

## Performance

| $n$        | $k$        | Our Method | C++ standard library |
|------------|------------|------------|----------------------|
| $10^6$     | $10^3$     | 1.42e-7    | 2.29e-7              |
| $10^6$     | $10^6$     | 2.68e-7    | 3.00e-7              |
| $10^6$     | $10^9$     | 2.71e-7    | 3.00e-7              |
