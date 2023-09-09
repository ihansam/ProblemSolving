from heapq import heappush, heappop


def solution(program):
    program.sort(key=lambda x: x[1], reverse=True)
    sys_time = 0
    waits = [0] * 11
    loaded = []

    while program or loaded:
        # 로드된 작업이 없으면 다음 호출 시각까지 idle
        if not loaded:
            sys_time = max(sys_time, program[-1][1])

        # 현재 시각 이전에 호출된 작업 로딩
        while program and program[-1][1] <= sys_time:
            heappush(loaded, program.pop())

        # 로딩된 한 가지 일 처리
        priority, call_time, exec_time = heappop(loaded)
        waits[priority] += (sys_time - call_time)
        sys_time += exec_time

    waits[0] = sys_time
    return waits
