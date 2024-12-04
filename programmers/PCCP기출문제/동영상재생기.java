// 12.04 13:34 - 14:24
class Solution {
    public String solution(String video_len, String pos, String op_start, String op_end, String[] commands) {
        String answer = "";
        
        // 0.시간은 초로 변경해서 사용 getSec(time) : string to int 
        // int sec_video_len, sec_pos, sec_op_start, sec_op_end
        int sec_video_len = getSec(video_len);
        int sec_pos = getSec(pos);
        int sec_op_start = getSec(op_start);
        int sec_op_end = getSec(op_end);

        // 1. commands 길이 반복문
        // isOp(pos) : pos가 opening에 있는 지 체크하고 그 안이면 return op_end 아니면 return op_start,
        // 조건문 1. prev일때 doPrev(pos) : return pos - 10 >= 0 ? pos - 10 : 0;
        // 조건문 2. next일때 doNext(pos) : return pos + 10 <= video_len ? pos + 10 : video_len
        for(String command : commands) {
            sec_pos = doOp(sec_op_start, sec_op_end, sec_pos);
            switch (command) {
                case "prev":
                    sec_pos = doPrev(sec_pos);
                    break;
            
                case "next":
                    sec_pos = doNext(sec_pos, sec_video_len);
                    break;
            }
        }

        
        // 2. 조건 완료 후 초를 시간으로 변경
        answer = getTimeString(doOp(sec_op_start, sec_op_end, sec_pos));
        return answer;
    }

    public int getSec(String time) {
            int min = Integer.parseInt(time.split(":")[0]);
            int sec = Integer.parseInt(time.split(":")[1]);
            return min*60 + sec;
    }

    public String getTimeString(int time) {
        String min = String.format("%02d", time/60);
        String sec = String.format("%02d", time%60);
        return min+":"+sec;
    }

    public int doOp(int op_start, int op_end, int pos) {
        return pos >= op_start && pos <= op_end ? op_end : pos;
    }

    public int doPrev(int pos) {
        return pos - 10 >= 0 ? pos - 10 : 0;
    }

    public int doNext(int pos, int video_len) {
        return pos + 10 <= video_len ? pos + 10 : video_len;
    }
    
}