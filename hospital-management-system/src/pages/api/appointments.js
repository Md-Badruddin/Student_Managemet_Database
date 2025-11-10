import { NextResponse } from 'next/server';

let appointments = [];

export async function GET(req) {
    return NextResponse.json(appointments);
}

export async function POST(req) {
    const appointment = await req.json();
    appointments.push(appointment);
    return NextResponse.json(appointment, { status: 201 });
}

export async function PUT(req) {
    const { id, ...updatedData } = await req.json();
    appointments = appointments.map(appointment => 
        appointment.id === id ? { ...appointment, ...updatedData } : appointment
    );
    return NextResponse.json(updatedData);
}

export async function DELETE(req) {
    const { id } = await req.json();
    appointments = appointments.filter(appointment => appointment.id !== id);
    return NextResponse.json({ message: 'Appointment deleted' });
}