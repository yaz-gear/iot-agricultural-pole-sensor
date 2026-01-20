import json

def log_sensor_data(payload):
    """
    Simplified logger function.
    In real project, logs would go to database or server.
    """
    data = json.loads(payload)
    print(f"Temperature: {data.get('temp')}C | Humidity: {data.get('humidity')}% | UV: {data.get('uv')}")

# Example usage
sample_payload = '{"temp":25.5,"humidity":60,"uv":3.2}'
log_sensor_data(sample_payload)
