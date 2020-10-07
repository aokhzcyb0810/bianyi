FROM alpine:3
RUN apk add cmake gcc g++ libgcc build-base make --no-cache
WORKDIR /app/
COPY ./* ./
RUN g++ task.cpp -o task
RUN chmod +x task
