class Timer {
  int saved_time;
  int total_time;
  
  Timer(int total_time) {
    this.total_time = total_time; 
  }
  
  void start() {
    saved_time = millis(); 
  }
  
  boolean is_finished() {
    int passed_time = millis() - saved_time;
    if (passed_time > total_time) {
      return true; 
    }
    else {
      return false; 
    }
  }
}
