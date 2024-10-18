class BrowserHistory {
private:
    stack<string> history,f;
public:
    BrowserHistory(string homepage) {
        history.push(homepage);
    }
    
    void visit(string url) {
        history.push(url);
        while(!f.empty()) f.pop();
    }
    
    string back(int steps) {
        while(steps and history.size()>1){
            f.push(history.top());
            history.pop();
            steps--;
        }
        return history.top();
    }
    
    string forward(int steps) {
        while(steps and !f.empty()){
            history.push(f.top());
            f.pop();
            steps--;
        }
        return history.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */