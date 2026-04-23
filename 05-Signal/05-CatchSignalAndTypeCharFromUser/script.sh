PID=$(pgrep run)
for i in $(seq 1 10000); do
    kill -SIGINT $PID
    sleep 0.1
done