nr, nc, np, nd, nq = list(map(int, input().split()))
#  5 <= nr <=  300
# 10 <= nc <= 1000
#  2 <= np <=   40
#  4 <= nd <= 300
#  3 <= nq <= 120 000
# li <= 10 000

roads = {}
# (li, fi) 道路長、一方通行かどうか
for _ in range(nr):
    cid, l, f = list(input().split())
    roads[cid] = (int(l), f == "1")

crosses_id = {}
crosses_edge = []
road_from = []
road_to = []
# road_from[i] は交差点iから伸びる道路
# (in_road_id, out_road_id)
for _ in range(nc):
    cid, rin, rout = input().split()
    

parks = {}
for _ in range(np):
    cid, r, s = input().split()
    parks[cid] = (r, int(s))


crosses_distance = [[1e9] * len(crosses_id) for _ in range(len(crosses_id))]
for cid in range(len(crosses_distance)):
    crosses_distance[cid][cid] = 0
for cid, ci_list in crosses:




for i in range(len(crosses_id)):
    for j in range(len(crosses_id)):
        for k in range(len(crosses_id)):
            crosses_distance[][k] = min()


def distance_daisya(start, end):
    return 0


def distance_car(start, end):
    return 0


for _ in range(nq):
    qt, start, end = input().split()
    if qt == '1':
        print(distance_daisya(start, end))
    else:
        print(distance_car(start, end))
