import React, { useState } from 'react';

const AppointmentForm = ({ onSubmit, initialData }) => {
    const [formData, setFormData] = useState(initialData || {
        patientName: '',
        appointmentDate: '',
        appointmentTime: '',
        reason: '',
    });

    const handleChange = (e) => {
        const { name, value } = e.target;
        setFormData({
            ...formData,
            [name]: value,
        });
    };

    const handleSubmit = (e) => {
        e.preventDefault();
        onSubmit(formData);
    };

    return (
        <form onSubmit={handleSubmit}>
            <div>
                <label>
                    Patient Name:
                    <input
                        type="text"
                        name="patientName"
                        value={formData.patientName}
                        onChange={handleChange}
                        required
                    />
                </label>
            </div>
            <div>
                <label>
                    Appointment Date:
                    <input
                        type="date"
                        name="appointmentDate"
                        value={formData.appointmentDate}
                        onChange={handleChange}
                        required
                    />
                </label>
            </div>
            <div>
                <label>
                    Appointment Time:
                    <input
                        type="time"
                        name="appointmentTime"
                        value={formData.appointmentTime}
                        onChange={handleChange}
                        required
                    />
                </label>
            </div>
            <div>
                <label>
                    Reason for Appointment:
                    <textarea
                        name="reason"
                        value={formData.reason}
                        onChange={handleChange}
                        required
                    />
                </label>
            </div>
            <button type="submit">Submit Appointment</button>
        </form>
    );
};

export default AppointmentForm;