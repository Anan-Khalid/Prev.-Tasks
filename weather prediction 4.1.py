from google.colab import drive
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

drive.mount('/content/drive')
file_path = '/content/drive/MyDrive/Weather Dataset.csv'

#loading the data
df = pd.read_csv(file_path)

# Remove duplicates
df = df.drop_duplicates()


# Plot the temperature vs time
plt.figure(figsize=(10, 6))
plt.plot(df['Formatted Date'], df['Temperature (C)'])
plt.xlabel("Time")
plt.ylabel("Temperature (Celsius)")
plt.axis([00,24,-5,45])
plt.title("Temperature Over Time")
plt.grid(True)

# Show the plot
plt.show()

#Histogram
plt.hist(df['Temperature (C)'])
plt.xlabel('Temperature (Celsius)')
plt.title('Temperature Distribution')
plt.show()

#Scatter Plot
plt.scatter(df['Temperature (C)'], df['Humidity'],s=10)
plt.xlabel('Temperature (Celsius)')
plt.ylabel('Humidity')
plt.axis([-5,45,0,1])
plt.title('Temperature vs. Humidity')
plt.show()

#Heatmap
numeric_df = df.select_dtypes(include=['number'])
correlation_matrix = numeric_df.corr()
sns.heatmap(correlation_matrix, annot=True)
plt.show()
