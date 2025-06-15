int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int req1, t1, req2, t2;
    std::cin >> req1 >> t1 >> req2 >> t2;

    std::cout << getMinUpgradationTime(req1, t1, req2, t2) << std::endl;

    return 0;
}