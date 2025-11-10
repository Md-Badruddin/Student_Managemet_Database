import { NextApiRequest, NextApiResponse } from 'next';

let patients = []; // This will act as an in-memory database for demonstration purposes

export default function handler(req, res) {
    switch (req.method) {
        case 'GET':
            res.status(200).json(patients);
            break;
        case 'POST':
            const newPatient = req.body;
            patients.push(newPatient);
            res.status(201).json(newPatient);
            break;
        case 'PUT':
            const { id } = req.query;
            const index = patients.findIndex(patient => patient.id === id);
            if (index !== -1) {
                patients[index] = { ...patients[index], ...req.body };
                res.status(200).json(patients[index]);
            } else {
                res.status(404).json({ message: 'Patient not found' });
            }
            break;
        default:
            res.setHeader('Allow', ['GET', 'POST', 'PUT']);
            res.status(405).end(`Method ${req.method} Not Allowed`);
    }
}