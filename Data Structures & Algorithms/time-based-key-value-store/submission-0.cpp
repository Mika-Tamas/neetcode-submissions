class TimeMap {
    unordered_map<string,map<int,string>> key_timestamp_value;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if (key_timestamp_value.find(key) == key_timestamp_value.end()) key_timestamp_value[key] = {};
        key_timestamp_value[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (key_timestamp_value.find(key) == key_timestamp_value.end()) return {};
        
        auto it = key_timestamp_value[key].upper_bound(timestamp);
        return it == key_timestamp_value[key].begin() ? "" : prev(it)->second;
    }
};
