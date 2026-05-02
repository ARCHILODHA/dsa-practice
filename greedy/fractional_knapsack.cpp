struct Item {
    int value, weight;
};

bool cmp(Item a, Item b) {
    return (double)a.value / a.weight > (double)b.value / b.weight;
}

double fractionalKnapsack(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), cmp);

    double total = 0.0;

    for(auto &item : items) {
        if(W >= item.weight) {
            total += item.value;
            W -= item.weight;
        } else {
            total += (double)item.value * (W / (double)item.weight);
            break;
        }
    }
    return total;
}
