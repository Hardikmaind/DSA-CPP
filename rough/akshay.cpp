// #include <iostream>
// #include <numeric> // For std::gcd
// #include <algorithm> // For std::min, std::max

// // long long gcd(long long a, long long b) {
// //     return std::gcd(a, b);
// // }


// // long long lcm(long long a, long long b) {
// //     if (a == 0 || b == 0) return 0;
// //     if (a == 1) return b;
// //     if (b == 1) return a;

// //     return (a / gcd(a, b)) * b;
// // }


// // bool isPossible(long long T, int req1, int t1, int req2, int t2) {
// //     // If T is 0, no upgrades can be done unless t1 and t2 are both 0.
// //     if (T == 0) {
// //         return (t1 == 0 && t2 == 0);
// //     }



// //     long long n_req1 = T / req1;
// //     long long n_req2 = T / req2;
    
// //     long long com_lcm = lcm(req1, req2);
// //     long long n_lcm = 0;
// //     if (com_lcm > 0) { // Should always be > 0 given req1, req2 >= 2
// //         n_lcm = T / com_lcm;
// //     }

// //     long long only_s1_can_work_count = n_req2 - n_lcm;


// //     long long only_s2_can_work_count = n_req1 - n_lcm;

// //     long long both_can_work_count = T - (n_req1 + n_req2 - n_lcm);

// //     long long current_t1 = t1;
// //     long long current_t2 = t2;

// //     long long taken_from_only_s1 = std::min(current_t1, only_s1_can_work_count);
// //     current_t1 -= taken_from_only_s1;

// //     long long taken_from_only_s2 = std::min(current_t2, only_s2_can_work_count);
// //     current_t2 -= taken_from_only_s2;

// //     long long total_remaining_needed = current_t1 + current_t2;

// //     return both_can_work_count >= total_remaining_needed;
// // }

// // long long getMinUpgradationTime(int req1, int t1, int req2, int t2) {
// //     // If no upgrades are needed, the time is 0.
// //     if ((long long)t1 + t2 == 0) return 0;


// //     long long low = 1;


// //     long long high = 2LL * 100000000000000LL; // 2 * 10^14.

// //     long long ans = -1; // Stores the minimum possible time

// //     while (low <= high) {
// //         long long mid = low + (high - low) / 2; // Calculate mid to prevent overflow
// //         if (isPossible(mid, req1, t1, req2, t2)) {
// //             ans = mid;         // mid is a possible answer, try for smaller time
// //             high = mid - 1;
// //         } else {
// //             low = mid + 1;     // mid is not enough, need more time
// //         }
// //     }
// //     return ans;
// // }

// // int main() {
// //     std::ios_base::sync_with_stdio(false);
// //     std::cin.tie(NULL);

// //     int req1, t1, req2, t2;
// //     std::cin >> req1 >> t1 >> req2 >> t2;

// //     std::cout << getMinUpgradationTime(req1, t1, req2, t2) << std::endl;

// //     return 0;
// // }


// long gcd(long a, long b) {
//     return std::gcd(a, b);
// }

// long lcm(long a, long b) {
//     if (a == 0 || b == 0) return 0;
//     if (a == 1) return b;
//     if (b == 1) return a;
//     return (a / gcd(a, b)) * b;
// }

// bool isPossible(long T, int req1, int t1, int req2, int t2) {
//     if (T == 0) return (t1 == 0 && t2 == 0);

//     long n_req1 = T / req1;
//     long n_req2 = T / req2;

//     long com_lcm = lcm(req1, req2);
//     long n_lcm = (com_lcm > 0) ? (T / com_lcm) : 0;

//     long only_s1_can_work_count = n_req2 - n_lcm;
//     long only_s2_can_work_count = n_req1 - n_lcm;
//     long both_can_work_count = T - (n_req1 + n_req2 - n_lcm);

//     long current_t1 = t1;
//     long current_t2 = t2;

//     long taken_from_only_s1 = std::min(current_t1, only_s1_can_work_count);
//     current_t1 -= taken_from_only_s1;

//     long taken_from_only_s2 = std::min(current_t2, only_s2_can_work_count);
//     current_t2 -= taken_from_only_s2;

//     long total_remaining_needed = current_t1 + current_t2;

//     return both_can_work_count >= total_remaining_needed;
// }

// long getMinUpgradationTime(int req1, int t1, int req2, int t2) {
//     if ((long)t1 + t2 == 0) return 0;

//     long low = 1;
//     long high = 2L * 100000000000000L;
//     long ans = -1;

//     while (low <= high) {
//         long mid = low + (high - low) / 2;
//         if (isPossible(mid, req1, t1, req2, t2)) {
//             ans = mid;
//             high = mid - 1;
//         } else {
//             low = mid + 1;
//         }
//     }
//     return ans;
// }


// int main() {
//     std::ios_base::sync_with_stdio(false);
//     std::cin.tie(NULL);

//     int req1, t1, req2, t2;
//     std::cin >> req1 >> t1 >> req2 >> t2;

//     std::cout << getMinUpgradationTime(req1, t1, req2, t2) << std::endl;

//     return 0;
// }




#include <iostream>
#include <numeric> // For std::gcd
#include <algorithm> // For std::min, std::max

long long gcd(long long a, long long b) {
    return std::gcd(a, b);
}


long long lcm(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    if (a == 1) return b;
    if (b == 1) return a;

    return (a / gcd(a, b)) * b;
}


bool isPossible(long long T, int req1, int t1, int req2, int t2) {
    // If T is 0, no upgrades can be done unless t1 and t2 are both 0.
    if (T == 0) {
        return (t1 == 0 && t2 == 0);
    }



    long long n_req1 = T / req1;
    long long n_req2 = T / req2;
    
    long long com_lcm = lcm(req1, req2);
    long long n_lcm = 0;
    if (com_lcm > 0) { // Should always be > 0 given req1, req2 >= 2
        n_lcm = T / com_lcm;
    }

    long long only_s1_can_work_count = n_req2 - n_lcm;


    long long only_s2_can_work_count = n_req1 - n_lcm;

    long long both_can_work_count = T - (n_req1 + n_req2 - n_lcm);

    long long current_t1 = t1;
    long long current_t2 = t2;

    long long taken_from_only_s1 = std::min(current_t1, only_s1_can_work_count);
    current_t1 -= taken_from_only_s1;

    long long taken_from_only_s2 = std::min(current_t2, only_s2_can_work_count);
    current_t2 -= taken_from_only_s2;

    long long total_remaining_needed = current_t1 + current_t2;

    return both_can_work_count >= total_remaining_needed;
}

long long getMinUpgradationTime(int req1, int t1, int req2, int t2) {
    // If no upgrades are needed, the time is 0.
    if ((long long)t1 + t2 == 0) return 0;


    long long low = 1;


    long long high = 2LL * 100000000000000LL; // 2 * 10^14.

    long long ans = -1; // Stores the minimum possible time

    while (low <= high) {
        long long mid = low + (high - low) / 2; // Calculate mid to prevent overflow
        if (isPossible(mid, req1, t1, req2, t2)) {
            ans = mid;         // mid is a possible answer, try for smaller time
            high = mid - 1;
        } else {
            low = mid + 1;     // mid is not enough, need more time
        }
    }
    return ans;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int req1, t1, req2, t2;
    std::cin >> req1 >> t1 >> req2 >> t2;

    std::cout << getMinUpgradationTime(req1, t1, req2, t2) << std::endl;

    return 0;
}

