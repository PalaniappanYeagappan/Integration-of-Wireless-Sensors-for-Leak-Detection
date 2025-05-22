
% ThingSpeak Leak Detection MATLAB Script
% Runs in ThingSpeak Cloud (Apps > MATLAB Analysis)

% Channel details
channelID = 1234567; % Replace with your actual channel ID
readAPIKey = 'YOUR_READ_API_KEY';

% Leak detection threshold
threshold = 6.5;

% Baseline pressure values (adjust based on your calibration)
baseline = [1010, 1010, 1010, 1010];

% Read latest data
data = thingSpeakRead(channelID, 'Fields', [1, 2, 3, 4, 8], ...
                      'NumPoints', 1, 'ReadKey', readAPIKey);

pressures = data(1:4);
leakFlag = data(5);

% Calculate deviations
deviation = abs(pressures - baseline);

% Debug output
fprintf('Pressures: %.2f, %.2f, %.2f, %.2f\n', pressures(1), pressures(2), pressures(3), pressures(4));
fprintf('Deviations: %.2f, %.2f, %.2f, %.2f\n', deviation(1), deviation(2), deviation(3), deviation(4));

% Check for leak condition
if leakFlag == 1 || any(deviation > threshold)
    % Send email alert
    sendEmail('youremail@example.com', ...
              'Leak Detected!', ...
              sprintf('Leak detected!\nPressures: %.2f, %.2f, %.2f, %.2f', ...
              pressures(1), pressures(2), pressures(3), pressures(4)));

    % Optional logging or secondary action can be added here
end
